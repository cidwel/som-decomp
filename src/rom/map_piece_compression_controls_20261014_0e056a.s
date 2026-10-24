.setcpu "65816"
.segment "CODE"
.org $056A
map_control_0e056a:
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
    .byte $E1 ; previous-row copy count
