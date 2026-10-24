.setcpu "65816"
.segment "CODE"
.org $3F50
map_control_0f3f50:
    .byte $EA ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
