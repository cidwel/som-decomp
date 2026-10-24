.setcpu "65816"
.segment "CODE"
.org $A056
map_control_0ea056:
    .byte $E2 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
