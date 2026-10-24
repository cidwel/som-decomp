.setcpu "65816"
.segment "CODE"
.org $6033
map_control_0f6033:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
