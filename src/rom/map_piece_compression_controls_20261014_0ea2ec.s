.setcpu "65816"
.segment "CODE"
.org $A2EC
map_control_0ea2ec:
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
