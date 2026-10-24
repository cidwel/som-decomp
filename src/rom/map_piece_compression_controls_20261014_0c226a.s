.setcpu "65816"
.segment "CODE"
.org $226A
map_control_0c226a:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
