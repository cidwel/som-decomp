.setcpu "65816"
.segment "CODE"
.org $884C
map_control_0f884c:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
