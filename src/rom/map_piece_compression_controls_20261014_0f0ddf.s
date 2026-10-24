.setcpu "65816"
.segment "CODE"
.org $0DDF
map_control_0f0ddf:
    .byte $E5 ; previous-row copy count
