.setcpu "65816"
.segment "CODE"
.org $958D
map_control_0f958d:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
