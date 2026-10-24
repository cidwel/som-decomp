.setcpu "65816"
.segment "CODE"
.org $D79B
map_control_0ed79b:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $61 ; row-distance/count
