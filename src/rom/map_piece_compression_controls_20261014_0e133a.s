.setcpu "65816"
.segment "CODE"
.org $133A
map_control_0e133a:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $41 ; distance low bit/count
