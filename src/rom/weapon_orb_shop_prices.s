; Weapon orb prices in GP indexed by already purchased level.
.setcpu "65816"
.segment "CODE"
.org $FCFB
weapon_orb_shop_prices:
weapon_orb_level_0_price:
    .word 200
weapon_orb_level_1_price:
    .word 400
weapon_orb_level_2_price:
    .word 800
weapon_orb_level_3_price:
    .word 1600
weapon_orb_level_4_price:
    .word 3000
weapon_orb_level_5_price:
    .word 6500
weapon_orb_level_6_price:
    .word 12500
weapon_orb_level_7_price:
    .word 25000
weapon_orb_level_8_price:
    .word 65535
