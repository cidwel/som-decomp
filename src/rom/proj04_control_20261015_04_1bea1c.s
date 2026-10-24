; Bits 7..0 select literal items 0..7; zero selects two-item history.
; Only contiguous low-byte masks; literals and M16 overfetch excluded.
.setcpu "65816"
.segment "RODATA"
.org $EA1C
history_only = $00
literal_item_0 = $80
literal_item_1 = $40
literal_item_2 = $20
literal_item_3 = $10
literal_item_4 = $08
literal_item_5 = $04
literal_item_6 = $02
literal_item_7 = $01
proj04_control_20261015_04_1bea1c:
    .byte (literal_item_1)
