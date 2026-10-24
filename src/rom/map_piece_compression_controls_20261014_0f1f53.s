.setcpu "65816"
.segment "CODE"
.org $1F53
map_control_0f1f53:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
