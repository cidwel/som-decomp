.setcpu "65816"
.segment "CODE"
.org $913D
map_control_0d913d:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count
