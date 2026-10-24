.setcpu "65816"
.segment "CODE"
.org $7F15
map_control_0c7f15:
    .byte $DC ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
