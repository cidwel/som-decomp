.setcpu "65816"
.segment "CODE"
.org $189C
map_control_0d189c:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
