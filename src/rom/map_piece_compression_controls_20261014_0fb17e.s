.setcpu "65816"
.segment "CODE"
.org $B17E
map_control_0fb17e:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
