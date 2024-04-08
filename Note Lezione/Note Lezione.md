---
database-plugin: basic
---

```yaml:dbfolder
name: Note Lezione
description: Tutte le note prese durante la lezione e rivisitate in seguito
columns:
  __file__:
    key: __file__
    id: __file__
    input: markdown
    label: File
    accessorKey: __file__
    isMetadata: true
    skipPersist: false
    isDragDisabled: false
    csvCandidate: true
    position: 0
    isHidden: false
    sortIndex: -1
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: true
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  Data:
    input: calendar
    accessorKey: Data
    key: Data
    id: Data
    label: Data
    position: 100
    skipPersist: false
    isHidden: false
    sortIndex: -1
    width: 86
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  Docente:
    input: text
    accessorKey: Docente
    key: Docente
    id: Docente
    label: Docente
    position: 100
    skipPersist: false
    isHidden: false
    sortIndex: -1
    width: 118
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  Argomenti:
    input: tags
    accessorKey: Argomenti
    key: Argomenti
    id: Argomenti
    label: Argomenti
    position: 100
    skipPersist: false
    isHidden: false
    sortIndex: -1
    width: 402
    options:
      - { label: "C", value: "C", color: "hsl(140, 95%, 90%)"}
      - { label: "File Binari", value: "File Binari", color: "hsl(84, 95%, 90%)"}
      - { label: "Gestione File", value: "Gestione File", color: "hsl(230, 95%, 90%)"}
      - { label: "Virtualizzazione", value: "Virtualizzazione", color: "hsl(186, 95%, 90%)"}
      - { label: "schede reti", value: "schede reti", color: "hsl(97, 95%, 90%)"}
      - { label: "Clonazione macchine", value: "Clonazione macchine", color: "hsl(116, 95%, 90%)"}
      - { label: "scp", value: "scp", color: "hsl(35, 95%, 90%)"}
      - { label: "Socket", value: "Socket", color: "hsl(1, 95%, 90%)"}
      - { label: "ssh", value: "ssh", color: "hsl(306, 95%, 90%)"}
      - { label: "UDP", value: "UDP", color: "hsl(104, 95%, 90%)"}
      - { label: "UD", value: "UD", color: "hsl(232, 95%, 90%)"}
      - { label: "sendto", value: "sendto", color: "hsl(299, 95%, 90%)"}
      - { label: "recvfrom", value: "recvfrom", color: "hsl(192, 95%, 90%)"}
      - { label: "bind", value: "bind", color: "hsl(49, 95%, 90%)"}
      - { label: "client - server", value: "client - server", color: "hsl(243, 95%, 90%)"}
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
      option_source: manual
      content_alignment: text-align-left
      content_vertical_alignment: align-middle
      wrap_content: true
  codice:
    input: text
    accessorKey: codice
    key: codice
    id: codice
    label: codice
    position: 100
    skipPersist: false
    isHidden: false
    sortIndex: -1
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
config:
  remove_field_when_delete_column: true
  cell_size: compact
  sticky_first_column: true
  group_folder_column: 
  remove_empty_folders: false
  automatically_group_files: false
  hoist_files_with_empty_attributes: true
  show_metadata_created: false
  show_metadata_modified: false
  show_metadata_tasks: false
  show_metadata_inlinks: false
  show_metadata_outlinks: false
  show_metadata_tags: false
  source_data: current_folder
  source_form_result: 
  source_destination_path: /
  row_templates_folder: _templates
  current_row_template: _templates/t_Lezione.md
  pagination_size: 30
  font_size: 16
  enable_js_formulas: true
  formula_folder_path: _js_formulas
  inline_default: false
  inline_new_position: last_field
  date_format: yyyy-MM-dd
  datetime_format: "yyyy-MM-dd HH:mm:ss"
  metadata_date_format: "yyyy-MM-dd HH:mm:ss"
  enable_footer: false
  implementation: default
filters:
  enabled: false
  conditions:
```
