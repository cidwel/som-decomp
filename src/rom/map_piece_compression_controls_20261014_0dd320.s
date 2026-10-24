.setcpu "65816"
.segment "CODE"
.org $D320
map_control_0dd320:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
