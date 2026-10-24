.setcpu "65816"
.segment "CODE"
.org $8033
map_control_0f8033:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
