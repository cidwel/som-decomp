.setcpu "65816"
.segment "CODE"
.org $E745
map_control_0fe745:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $4E ; row-distance/count
