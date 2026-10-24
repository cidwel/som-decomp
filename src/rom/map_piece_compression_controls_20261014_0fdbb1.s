.setcpu "65816"
.segment "CODE"
.org $DBB1
map_control_0fdbb1:
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
