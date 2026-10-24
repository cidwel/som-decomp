.setcpu "65816"
.segment "CODE"
.org $DBA4
map_control_0edba4:
    .byte $EE ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
