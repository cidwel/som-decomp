; Four-byte copied JML vector template, not ROM-executed instruction credit.
.setcpu "65816"
.segment "RODATA"
.org $AC22
world_map_survey_nmi_vector_template:
    .byte $5C ; JML opcode copied to RAM000100
    .faraddr $00AC26 ; installed native handler address
