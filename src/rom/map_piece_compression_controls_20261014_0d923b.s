.setcpu "65816"
.segment "CODE"
.org $923B
map_control_0d923b:
    .byte $E0 ; previous-row copy escape
    .byte $90 ; row-distance/count
