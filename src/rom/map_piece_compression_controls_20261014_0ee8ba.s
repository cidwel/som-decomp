.setcpu "65816"
.segment "CODE"
.org $E8BA
map_control_0ee8ba:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
