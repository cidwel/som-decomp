.setcpu "65816"
.segment "CODE"
.org $DC5A
map_control_0edc5a:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E1 ; previous-row copy count
