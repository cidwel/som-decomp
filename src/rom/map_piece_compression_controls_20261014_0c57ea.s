.setcpu "65816"
.segment "CODE"
.org $57EA
map_control_0c57ea:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
