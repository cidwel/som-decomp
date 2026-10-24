.setcpu "65816"
.segment "CODE"
.org $A568
map_control_0ea568:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
