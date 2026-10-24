.setcpu "65816"
.segment "CODE"
.org $AF1B
map_control_0daf1b:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
