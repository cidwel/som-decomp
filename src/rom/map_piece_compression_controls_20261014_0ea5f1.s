.setcpu "65816"
.segment "CODE"
.org $A5F1
map_control_0ea5f1:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
