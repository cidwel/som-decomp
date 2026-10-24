.setcpu "65816"
.segment "CODE"
.org $16DB
map_control_0d16db:
    .byte $F1 ; progressive-copy count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
