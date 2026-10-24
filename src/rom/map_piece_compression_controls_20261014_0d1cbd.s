.setcpu "65816"
.segment "CODE"
.org $1CBD
map_control_0d1cbd:
    .byte $E1 ; previous-row copy count
