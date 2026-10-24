.setcpu "65816"
.segment "CODE"
.org $E00C
map_control_0ee00c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
