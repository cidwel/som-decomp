.setcpu "65816"
.segment "CODE"
.org $32DF
map_control_0f32df:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
