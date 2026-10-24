.setcpu "65816"
.segment "CODE"
.org $474D
map_control_0c474d:
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
