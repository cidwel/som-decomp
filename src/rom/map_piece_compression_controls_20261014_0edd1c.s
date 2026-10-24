.setcpu "65816"
.segment "CODE"
.org $DD1C
map_control_0edd1c:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $39 ; row-distance/count
