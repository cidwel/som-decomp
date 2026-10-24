.setcpu "65816"
.segment "CODE"
.org $D762
map_control_0ed762:
    .byte $DC ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
