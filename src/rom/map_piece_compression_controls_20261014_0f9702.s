.setcpu "65816"
.segment "CODE"
.org $9702
map_control_0f9702:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
