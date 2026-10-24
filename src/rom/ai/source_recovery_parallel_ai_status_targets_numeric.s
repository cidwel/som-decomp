; Relative AI PC offsets, status selector domains0..2 only.
.setcpu "65816"
.segment "CODE"
.org $4ED3
.macro ai_status_program_target target_pc
    .word target_pc
.endmacro
status_selector_0_entry:
    ai_status_program_target $5A35
status_selector_1_entry:
    ai_status_program_target $6378
status_selector_2_entry:
    ai_status_program_target $648E
