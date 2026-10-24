.setcpu "65816"
.segment "CODE"
.org $3371
map_control_0f3371:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E6 ; previous-row copy count
