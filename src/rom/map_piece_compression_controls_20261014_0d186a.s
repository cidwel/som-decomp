.setcpu "65816"
.segment "CODE"
.org $186A
map_control_0d186a:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
