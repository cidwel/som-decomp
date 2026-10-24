.setcpu "65816"
.segment "CODE"
.org $F92D
map_control_0df92d:
    .byte $E2 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
