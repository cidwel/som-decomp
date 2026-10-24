.setcpu "65816"
.segment "CODE"
.org $1F47
map_control_0f1f47:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
