.setcpu "65816"
.segment "CODE"
.org $0391
map_control_0e0391:
    .byte $E3 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
