; Numeric ten-byte control descriptor selected at 7ED171; resource C7B480.
.setcpu "65816"
.segment "RODATA"
.org $6492
entry_control = $7ED0CC
cold_control_task_descriptor:
    .faraddr entry_control
    .byte $74 ; AAFF task priority
    .word $0000 ; zero repeated-entry word
    .word $0100 ; copied descriptor word6, no allocation interpretation
    .word $0000 ; AAFF optional workspace bytes
