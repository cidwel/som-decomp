.setcpu "65816"
.segment "CODE"
.org $584A
map_control_0f584a:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count
