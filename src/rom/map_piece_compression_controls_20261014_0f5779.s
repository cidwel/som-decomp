.setcpu "65816"
.segment "CODE"
.org $5779
map_control_0f5779:
    .byte $C7 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
