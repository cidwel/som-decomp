.setcpu "65816"
.segment "CODE"
.org $643C
map_control_0f643c:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
