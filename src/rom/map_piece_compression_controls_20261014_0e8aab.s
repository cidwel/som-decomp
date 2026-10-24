.setcpu "65816"
.segment "CODE"
.org $8AAB
map_control_0e8aab:
    .byte $E4 ; previous-row copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $DF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
