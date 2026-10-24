.setcpu "65816"
.segment "CODE"
.org $F851
map_control_0df851:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count
