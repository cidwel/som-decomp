.setcpu "65816"
.segment "CODE"
.org $7033
map_control_0e7033:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
