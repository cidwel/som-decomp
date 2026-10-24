; Native numerical/vector data consumed by the verified picker dependencies.
.setcpu "65816"
.segment "CODE"
.org $A646
world_map_picker_copied_nmi_jump_template:
    .byte $5C
    .word $A64A
    .byte $00
