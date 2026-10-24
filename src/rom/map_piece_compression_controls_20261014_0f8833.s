.setcpu "65816"
.segment "CODE"
.org $8833
map_control_0f8833:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
