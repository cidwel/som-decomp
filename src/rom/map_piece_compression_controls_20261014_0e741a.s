.setcpu "65816"
.segment "CODE"
.org $741A
map_control_0e741a:
    .byte $E0 ; previous-row copy escape
    .byte $96 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
