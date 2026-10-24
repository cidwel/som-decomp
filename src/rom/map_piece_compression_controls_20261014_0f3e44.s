.setcpu "65816"
.segment "CODE"
.org $3E44
map_control_0f3e44:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
