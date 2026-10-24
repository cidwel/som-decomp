.setcpu "65816"
.segment "CODE"
.org $A66C
map_control_0ea66c:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
