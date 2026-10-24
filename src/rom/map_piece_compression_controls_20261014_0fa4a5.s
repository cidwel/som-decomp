.setcpu "65816"
.segment "CODE"
.org $A4A5
map_control_0fa4a5:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $24 ; distance low bit/count
